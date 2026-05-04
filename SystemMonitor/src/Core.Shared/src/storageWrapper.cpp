#include "../pch.h"
#include "../include/storageWrapper.h"
#include <iostream>
#include <msclr/marshal_cppstd.h>

namespace share {
	namespace core {

		clsStorageWrapper::clsStorageWrapper(){
			storageReader = new hardwares::storage::clsStorage_reader;
		}

		clsStorageWrapper::~clsStorageWrapper() {
			this->!clsStorageWrapper();
		}

		clsStorageWrapper::!clsStorageWrapper() {
			if (storageReader != nullptr)
			{
				delete storageReader;
				storageReader = nullptr;
			}
		}
		
		double clsStorageWrapper::getTotalSpaceGB(String^ drivePath) {
			return storageReader->getTotalSpaceGB(msclr::interop::marshal_as<std::wstring>(drivePath));
		}

		double clsStorageWrapper::getFreeSpaceGB(String^ drivePath) {
			return storageReader->getFreeSpaceGB(msclr::interop::marshal_as<std::wstring>(drivePath));
		}

		double clsStorageWrapper::getUsedSpaceGB(String^ drivePath) {
			return storageReader->getUsedSpaceGB(msclr::interop::marshal_as<std::wstring>(drivePath));
		}

		int clsStorageWrapper::getUsagePercentage(String^ drivePath) {
			return storageReader->getUsagePercentage(msclr::interop::marshal_as<std::wstring>(drivePath));
		}

		List<String^>^ clsStorageWrapper::getDriveList() {
			List<String^>^ managedList = gcnew List<String^>();
			std::vector<std::wstring> drives = storageReader->getDriveList();

			for (const std::wstring &drive: drives)
			{
				managedList->Add(msclr::interop::marshal_as<String^>(drive));
			}
			return managedList;
		}

	}
}