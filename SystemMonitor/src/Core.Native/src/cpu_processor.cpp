#include "../pch.h"
#include "../include/cpu_reader.h"

namespace hardwares {
	namespace cpu {

		clsCpu_Reader::clsCpu_Reader()
		{
		  // Open a query
			if (PdhOpenQuery(NULL,NULL,&cpu_query) != ERROR_SUCCESS)
			{
				
			}

			// Add the counter to the query
			PdhAddCounter(cpu_query, L"\\Processor(_Total)\\% Processor Time", NULL, &cpu_counter);

			// Collect initial data
			PdhCollectQueryData(cpu_query);
		}
		hardwares::cpu::clsCpu_Reader::~clsCpu_Reader() {
			// Close the query to prevent windows monitoring CPU and cause Resource Leak.
			
			if (cpu_query)
			{
				PdhCloseQuery(cpu_query);
			}
			
			/* notice: if you forget to close the query, windows will keep monitoring CPU
			 and cause Resource Leak Even if you close App.*/
		}

		double hardwares::cpu::clsCpu_Reader::getCpuUsage() {
			PDH_FMT_COUNTERVALUE counter_value;

			// Collect the latest date.
			PdhCollectQueryData(cpu_query);

			// PDH_FMT_DOUBLE :windows understand the counter value should be a double number.
			PdhGetFormattedCounterValue(cpu_counter, PDH_FMT_DOUBLE, NULL, &counter_value);

			return counter_value.doubleValue;
		}
	}
}