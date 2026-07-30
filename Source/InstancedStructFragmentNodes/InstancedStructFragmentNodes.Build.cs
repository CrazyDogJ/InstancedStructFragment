using UnrealBuildTool;

public class InstancedStructFragmentNodes : ModuleRules
{
    public InstancedStructFragmentNodes(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core", 
                "CoreUObject", 
                "InstancedStructFragment",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "KismetCompiler",  
                "UnrealEd",
                "BlueprintGraph",
                "InstancedStructFragment",
            }
        );
    }
}