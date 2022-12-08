using Copium.BuildTool;
using Copium.Core.Net7;


internal sealed class CopiumCore : CopiumCppProject
{
    public CopiumCore(DirectoryItem outputDir)
        : base("Copium.Core", outputDir)
    {
        BaseGeneratedIncludeDir = "CopiumCoreCht";

        SetConfigurationMatrix(new CopiumCppConfigurationMatrix(OutputType.StaticLib));

        AddSourcesDir();
    }


    protected override void OnConfigureCopiumProject(CopiumCppConfiguration configuration)
    {
        if (configuration.OS == BuildOS.Windows)
        {
            configuration.PublicDefines.AddRange(new[] {
                "WIN32_LEAN_AND_MEAN",
                "UNICODE",
                "_UNICODE",
                "_CRT_SECURE_NO_WARNINGS",
                "COP_PLATFORM_WINDOWS",
            });
        }

        if (configuration.Compiler == BuildCompiler.Msvc)
        {
            configuration.PublicDefines.Add("COP_COMPILER_MSVC");
        }

        switch (configuration.Configuration)
        {
            case BuildConfiguration.Debug:
                configuration.PublicDefines.Add("COP_CONFIGURATION_DEBUG");
                break;
            case BuildConfiguration.Development:
                configuration.PublicDefines.Add("COP_CONFIGURATION_DEVELOPMENT");
                break;
            case BuildConfiguration.Release:
                configuration.PublicDefines.Add("COP_CONFIGURATION_RELEASE");
                break;
        }

        configuration.PublicConanLibs.Add(ConanLibrary.spdlog);
    }
}