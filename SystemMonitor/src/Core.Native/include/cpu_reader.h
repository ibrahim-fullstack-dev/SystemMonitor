#pragma once // include only once.
#include <Windows.h> // for transaction with windows API.
#include <Pdh.h> // for performance date helper API.

#pragma comment(lib, "Pdh.lib") // link program with Pdh.lib.

namespace hardwares {
	namespace cpu {
		class clsCpu_Reader {

		private:

			PDH_HQUERY query; // handle for the query.
			PDH_HCOUNTER counter; // handle for the counter.
		public:
			clsCpu_Reader(); 
			~clsCpu_Reader();

			double getCpuUsage();

		};
	}
}