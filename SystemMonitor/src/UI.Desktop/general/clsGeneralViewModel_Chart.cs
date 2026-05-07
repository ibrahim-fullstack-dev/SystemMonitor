using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LiveChartsCore;
using LiveChartsCore.Kernel.Sketches;
using LiveChartsCore.SkiaSharpView;
using LiveChartsCore.SkiaSharpView.Painting;
using SkiaSharp;

namespace UI.Desktop.Global;

public abstract class clsGeneralViewModel_Chart
{
    public ObservableCollection<double> Data { get; set; } = new();

    public ISeries[] Series { get; set; }

    public Axis[] YAxes { get; set; }

    protected clsGeneralViewModel_Chart(string title, SKColor FillColor, SKColor StrokeColor)
    {
        Series = new ISeries[]
        {
            new LineSeries<double>
            {
                Name = title,
                Values = Data,
                Fill = new SolidColorPaint(FillColor),
                Stroke = new SolidColorPaint(StrokeColor) { StrokeThickness = 1 },
                GeometrySize = 0
            }
        };
        YAxes = new Axis[]
        {
            new Axis
            {
                MinLimit = 0,
                MaxLimit = 100,
            }
        };
    }

    public void Update(double value)
    {
        Data.Add(value);
        if (Data.Count > 30) // Keep only the latest 30 data points
        {
            Data.RemoveAt(0);
        }
    }

}
