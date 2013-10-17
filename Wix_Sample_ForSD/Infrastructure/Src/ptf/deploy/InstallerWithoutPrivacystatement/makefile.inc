!INCLUDE $(INETROOT)\build\makefile.inc

#-------------------------------------------------------------------------------
# Code Signing in official retail build.
#
# Important tips for code signing
# - Code signing is required for shipping binaries 
# - Make sure %inetroot%\build\automation\CodeSignTool\CS_Files.txt is updated with files you want to sign
# - All managed binaries need Strong Name sign and Authenticode sign.
# - All native binaries and MSI files need Authenticode sign.

CodeSignMSI:
!if "$(OFFICIAL_SIGN)" == "1"
    $(CODESIGN_CMD) %INETROOT%\%INFRASTRUCTURE_DROP%\deploy\InstallerWithoutPrivacystatement $(CODESIGN_PATH)\CS_Config.xml PTF_MSIFILES
!endif