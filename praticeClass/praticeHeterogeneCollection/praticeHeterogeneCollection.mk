##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=praticeHeterogeneCollection
ConfigurationName      :=Debug
WorkspacePath          := "/home/david/perso/c++/praticeClass"
ProjectPath            := "/home/david/perso/c++/praticeClass/praticeHeterogeneCollection"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=David
Date                   :=11/01/17
CodeLitePath           :="/home/david/.codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="praticeHeterogeneCollection.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Auto.cpp$(ObjectSuffix) $(IntermediateDirectory)/Moto.cpp$(ObjectSuffix) $(IntermediateDirectory)/Vehicule.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/david/perso/c++/praticeClass/praticeHeterogeneCollection/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Auto.cpp$(ObjectSuffix): Auto.cpp $(IntermediateDirectory)/Auto.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/david/perso/c++/praticeClass/praticeHeterogeneCollection/Auto.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Auto.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Auto.cpp$(DependSuffix): Auto.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Auto.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Auto.cpp$(DependSuffix) -MM "Auto.cpp"

$(IntermediateDirectory)/Auto.cpp$(PreprocessSuffix): Auto.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Auto.cpp$(PreprocessSuffix) "Auto.cpp"

$(IntermediateDirectory)/Moto.cpp$(ObjectSuffix): Moto.cpp $(IntermediateDirectory)/Moto.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/david/perso/c++/praticeClass/praticeHeterogeneCollection/Moto.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Moto.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Moto.cpp$(DependSuffix): Moto.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Moto.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Moto.cpp$(DependSuffix) -MM "Moto.cpp"

$(IntermediateDirectory)/Moto.cpp$(PreprocessSuffix): Moto.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Moto.cpp$(PreprocessSuffix) "Moto.cpp"

$(IntermediateDirectory)/Vehicule.cpp$(ObjectSuffix): Vehicule.cpp $(IntermediateDirectory)/Vehicule.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/david/perso/c++/praticeClass/praticeHeterogeneCollection/Vehicule.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Vehicule.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Vehicule.cpp$(DependSuffix): Vehicule.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Vehicule.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Vehicule.cpp$(DependSuffix) -MM "Vehicule.cpp"

$(IntermediateDirectory)/Vehicule.cpp$(PreprocessSuffix): Vehicule.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Vehicule.cpp$(PreprocessSuffix) "Vehicule.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


