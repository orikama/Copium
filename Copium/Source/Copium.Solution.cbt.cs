using Copium.BuildTool;
using Copium.Core.Net7;


internal sealed class CopiumSolution : Solution
{
    public CopiumSolution()
        : base("Copium", Globals.Build.ProjectDir.MakeSubDirItem("vs"))
    {
        AddProject(new CopiumEngine(OutputDir));
        AddProject(new CopiumEngineTests(OutputDir));
        AddProject(new CopiumEditor(OutputDir));
    }
}
