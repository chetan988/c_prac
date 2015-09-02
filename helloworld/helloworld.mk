##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=helloworld
ConfigurationName      :=Debug
WorkspacePath          := "D:\myc\helloworld"
ProjectPath            := "D:\myc\helloworld"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=chedas
Date                   :=09/16/14
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=C:\MinGW-4.8.1\bin\g++.exe 
SharedObjectLinkerName :=C:\MinGW-4.8.1\bin\g++.exe -shared -fPIC
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
ObjectsFileList        :="helloworld.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:\MinGW-4.8.1\bin\windres.exe 
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
AR       := C:\MinGW-4.8.1\bin\ar.exe rcu
CXX      := C:\MinGW-4.8.1\bin\g++.exe 
CC       := C:\MinGW-4.8.1\bin\gcc.exe 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:\MinGW-4.8.1\bin\as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/heapsort.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/heapsort.c$(ObjectSuffix): heapsort.c $(IntermediateDirectory)/heapsort.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/myc/helloworld/heapsort.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/heapsort.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/heapsort.c$(DependSuffix): heapsort.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/heapsort.c$(ObjectSuffix) -MF$(IntermediateDirectory)/heapsort.c$(DependSuffix) -MM "heapsort.c"

$(IntermediateDirectory)/heapsort.c$(PreprocessSuffix): heapsort.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/heapsort.c$(PreprocessSuffix) "heapsort.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/heapsort.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/heapsort.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/heapsort.c$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-debug/helloworld"


