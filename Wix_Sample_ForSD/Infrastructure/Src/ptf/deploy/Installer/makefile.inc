!INCLUDE $(INETROOT)\build\makefile.inc

#-------------------------------------------------------------------------------
# Code Signing in official retail build.
#
# Important tips for code signing
# - Code signing is required for shipping binaries 
# - Make sure %inetroot%\build\automation\CodeSignTool\CS_Files.txt is updated with files you want to sign
# - All managed binaries need Strong Name sign and Authenticode sign.
# - All native binaries and MSI files need Authenticode sign.

CodeSign:
!if "$(OFFICIAL_SIGN)" == "1"
    $(CODESIGN_CMD) %INETROOT%\%INFRASTRUCTURE_DROP%\ptf\vs9 $(CODESIGN_PATH)\CS_SN_Config.xml PTF_STRONGNAMEFILES
    $(CODESIGN_CMD) %INETROOT%\%INFRASTRUCTURE_DROP%\ptf\vs9 $(CODESIGN_PATH)\CS_Config.xml PTF_WIN32FILES
    $(CODESIGN_CMD) %INETROOT%\%INFRASTRUCTURE_DROP%\ptf\vs10 $(CODESIGN_PATH)\CS_SN_Config.xml PTF_STRONGNAMEFILES
    $(CODESIGN_CMD) %INETROOT%\%INFRASTRUCTURE_DROP%\ptf\vs10 $(CODESIGN_PATH)\CS_Config.xml PTF_WIN32FILES
    $(CODESIGN_CMD) %INETROOT%\%INFRASTRUCTURE_DROP%\ptf\reportingtool $(CODESIGN_PATH)\CS_SN_Config.xml REPORT_STRONGNAMEFILES
    $(CODESIGN_CMD) %INETROOT%\%INFRASTRUCTURE_DROP%\ptf\reportingtool $(CODESIGN_PATH)\CS_Config.xml REPORT_WIN32FILES
    $(CODESIGN_CMD) %INETROOT%\%INFRASTRUCTURE_DROP%\pac $(CODESIGN_PATH)\CS_SN_Config.xml PAC_STRONGNAMEFILES
    $(CODESIGN_CMD) %INETROOT%\%INFRASTRUCTURE_DROP%\pac $(CODESIGN_PATH)\CS_Config.xml PAC_WIN32FILES
!endif

CodeSignMSI:
!if "$(OFFICIAL_SIGN)" == "1"
    $(CODESIGN_CMD) %INETROOT%\%INFRASTRUCTURE_DROP%\deploy $(CODESIGN_PATH)\CS_Config.xml PTF_MSIFILES
!endif