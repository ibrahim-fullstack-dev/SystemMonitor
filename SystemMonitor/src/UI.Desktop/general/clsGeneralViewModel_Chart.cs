using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LiveChartsCore;
using System.Linq;
using LiveChartsCore.Kernel.Sketches;
using LiveChartsCore.SkiaSharpView;
using LiveChartsCore.SkiaSharpView.Painting;
using LiveChartsCore.SkiaSharpView.Painting.Effects;
using SkiaSharp;

namespace UI.Desktop.Global;

public abstract class clsGeneralViewModel_Chart
{
    public ObservableCollection<double> Data { get; set; }

    public ISeries[] Series { get; set; }

    public Axis[] YAxes { get; set; } =
{
    new Axis
    {
        SeparatorsPaint = new SolidColorPaint
        {
            Color = SKColors.LightBlue.WithAlpha(30),
            StrokeThickness = 1
        },
        MinLimit = 0,
        MaxLimit = 100,
        LabelsPaint = new SolidColorPaint(SKColors.Green)
    }
};
    public Axis[] XAxes { get; set; } =
 {
    new Axis
    {
        SeparatorsPaint = new SolidColorPaint
        {
            Color = SKColors.LightBlue.WithAlpha(30), 
            StrokeThickness = 1,
            PathEffect = new DashEffect(new float[] { 3, 3 }) 
        },
        LabelsPaint = new SolidColorPaint(SKColors.Green)
    }
};

    protected clsGeneralViewModel_Chart(string title, SKColor FillColor, SKColor StrokeColor)
    {
        Data = new ObservableCollection<double>() { 0.0, 20 };
        
        Series = new ISeries[]
        {
            new LineSeries<double>
            {
                Name = title,
                Values = Data,
                Fill = new LinearGradientPaint(
                  new SKColor[] { StrokeColor.WithAlpha(120), StrokeColor.WithAlpha(0) },
                  new SKPoint(0.5f, 0),
                  new SKPoint(0.5f, 1)),

                Stroke = new SolidColorPaint(StrokeColor) { StrokeThickness = 1 },
                LineSmoothness = 0.6,
                GeometrySize = 0,

            }

        };

    }

    public void Update(double value)
    {
        Data.Add(value);
        if (Data.Count > 20) // Keep only the latest 20 data points
        {
            Data.RemoveAt(0);
        }
    }

}
