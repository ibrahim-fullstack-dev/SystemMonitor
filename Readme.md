# IbrahimMonitor (System Pulse)

Enterprise-level system monitoring application built with C++ and C#.

## 🏗 Architecture

- **Core.Native (C++)**: High-performance hardware data collection using PDH API.
- **Core.Shared (C#)**: Business logic and SQLite data management.
- **Background.Worker**: Windows Service for 24/7 monitoring.
- **Desktop (WPF)**: Professional dashboard for data visualization.

## 🚀 Tech Stack

- C++ (Native & CLI/C++ Bridge)
- C# .NET 8
- WPF (XAML)
- SQLite / Entity Framework Core

## Testing

- To run the hardware monitoring tests, set the Startup Project (Run Mode) to Core.Native.tests within Visual Studio.
