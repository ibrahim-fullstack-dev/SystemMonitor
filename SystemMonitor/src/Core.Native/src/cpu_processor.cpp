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
			if (PdhAddCounter(cpu_query, L"\\Processor(_Total)\\% Processor Time",NULL,&cpu_counter))
			{

			}
		}
	}
}