##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=blockchain
ConfigurationName      :=Debug
WorkspacePath          :=/home/david/dev/learn-cpp/graph/graph
ProjectPath            :=/home/david/dev/learn-cpp/blockchain
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=root
Date                   :=06/07/18
CodeLitePath           :=/root/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
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
ObjectsFileList        :="blockchain.txt"
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
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Block.cpp$(ObjectSuffix) $(IntermediateDirectory)/sha256.cpp$(ObjectSuffix) $(IntermediateDirectory)/Blockchain.cpp$(ObjectSuffix) 



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
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/david/dev/learn-cpp/blockchain/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Block.cpp$(ObjectSuffix): Block.cpp $(IntermediateDirectory)/Block.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/david/dev/learn-cpp/blockchain/Block.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Block.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Block.cpp$(DependSuffix): Block.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Block.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Block.cpp$(DependSuffix) -MM Block.cpp

$(IntermediateDirectory)/Block.cpp$(PreprocessSuffix): Block.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Block.cpp$(PreprocessSuffix) Block.cpp

$(IntermediateDirectory)/sha256.cpp$(ObjectSuffix): sha256.cpp $(IntermediateDirectory)/sha256.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/david/dev/learn-cpp/blockchain/sha256.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sha256.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sha256.cpp$(DependSuffix): sha256.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sha256.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/sha256.cpp$(DependSuffix) -MM sha256.cpp

$(IntermediateDirectory)/sha256.cpp$(PreprocessSuffix): sha256.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sha256.cpp$(PreprocessSuffix) sha256.cpp

$(IntermediateDirectory)/Blockchain.cpp$(ObjectSuffix): Blockchain.cpp $(IntermediateDirectory)/Blockchain.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/david/dev/learn-cpp/blockchain/Blockchain.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Blockchain.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Blockchain.cpp$(DependSuffix): Blockchain.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Blockchain.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Blockchain.cpp$(DependSuffix) -MM Blockchain.cpp

$(IntermediateDirectory)/Blockchain.cpp$(PreprocessSuffix): Blockchain.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Blockchain.cpp$(PreprocessSuffix) Blockchain.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


