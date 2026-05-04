
#include "../pch.h"

#include "../../Core.Native/include/storage_reader.h"

#include "../include/storageWrapper.h"

#include <msclr/marshal_cppstd.h>

namespace share {
	namespace core {

		clsStorageWrapper::clsStorageWrapper(){
			storageReader = new ::hardwares::storage::clsStorage_reader;
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
		
		double clsStorageWrapper::getTotalSpaceGB(System::String^ drivePath) {
			std::wstring nativePath = msclr::interop::marshal_as<std::wstring>(drivePath);
			return static_cast<::hardwares::storage::clsStorage_reader*>(storageReader)->getTotalSpaceGB(nativePath);
		}

		double clsStorageWrapper::getFreeSpaceGB(System::String^ drivePath) {
			std::wstring nativePath = msclr::interop::marshal_as<std::wstring>(drivePath);
			return static_cast<::hardwares::storage::clsStorage_reader*>(storageReader)->getFreeSpaceGB(nativePath);
		}

		double clsStorageWrapper::getUsedSpaceGB(System::String^ drivePath) {
			std::wstring nativePath = msclr::interop::marshal_as<std::wstring>(drivePath);
			return static_cast<::hardwares::storage::clsStorage_reader*>(storageReader)->getUsedSpaceGB(nativePath);
		}

		int clsStorageWrapper::getUsagePercentage(System::String^ drivePath) {
			std::wstring nativePath = msclr::interop::marshal_as<std::wstring>(drivePath);
			return static_cast<::hardwares::storage::clsStorage_reader*>(storageReader)->getUsagePercentage(nativePath);
		}

		System::Collections::Generic::List<System::String^>^ clsStorageWrapper::getDriveList() {
			System::Collections::Generic::List<System::String^>^ managedList = gcnew System::Collections::Generic::List<System::String^>();
			std::vector<std::wstring> drives = static_cast<::hardwares::storage::clsStorage_reader*>(storageReader)->getDriveList();

			for (const std::wstring &drive: drives)
			{
				managedList->Add(msclr::interop::marshal_as<System::String^>(drive));
			}
			return managedList;
		}

	}
}