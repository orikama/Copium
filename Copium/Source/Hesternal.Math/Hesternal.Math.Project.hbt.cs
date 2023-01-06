using Copium.BuildTool;
using Copium.Core.Net7;


internal sealed class HesternalMath : HesternalCppProject
{
    public HesternalMath(DirectoryItem outputDir)
        : base("Hesternal.Math", outputDir)
    {
        SetConfigurationMatrix(new HesternalCppConfigurationMatrix(OutputType.StaticLib));

        AddPublicProjectReference<HesternalCore>();

        AddSourcesDir();
    }
}
