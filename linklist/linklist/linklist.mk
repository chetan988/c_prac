##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=linklist
ConfigurationName      :=Debug
WorkspacePath          := "D:\myc\helloworld\linklist"
ProjectPath            := "D:\myc\helloworld\linklist\linklist"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=chedas
Date                   :=09/26/14
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
ObjectsFileList        :="linklist.txt"
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
Objects0=$(IntermediateDirectory)/insertnode.c$(ObjectSuffix) $(IntermediateDirectory)/even_odd_arrange.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/insertnode.c$(ObjectSuffix): insertnode.c $(IntermediateDirectory)/insertnode.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/myc/helloworld/linklist/linklist/insertnode.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/insertnode.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/insertnode.c$(DependSuffix): insertnode.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/insertnode.c$(ObjectSuffix) -MF$(IntermediateDirectory)/insertnode.c$(DependSuffix) -MM "insertnode.c"

$(IntermediateDirectory)/insertnode.c$(PreprocessSuffix): insertnode.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/insertnode.c$(PreprocessSuffix) "insertnode.c"

$(IntermediateDirectory)/even_odd_arrange.c$(ObjectSuffix): even_odd_arrange.c $(IntermediateDirectory)/even_odd_arrange.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/myc/helloworld/linklist/linklist/even_odd_arrange.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/even_odd_arrange.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/even_odd_arrange.c$(DependSuffix): even_odd_arrange.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/even_odd_arrange.c$(ObjectSuffix) -MF$(IntermediateDirectory)/even_odd_arrange.c$(DependSuffix) -MM "even_odd_arrange.c"

$(IntermediateDirectory)/even_odd_arrange.c$(PreprocessSuffix): even_odd_arrange.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/even_odd_arrange.c$(PreprocessSuffix) "even_odd_arrange.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/insertnode.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/insertnode.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/insertnode.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/even_odd_arrange.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/even_odd_arrange.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/even_odd_arrange.c$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-debug/linklist"


