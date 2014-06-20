//
//  ARUPDATER_Updater.h
//  ARUpdaterCLibProject
//
//  Created by Djavan Bertrand on 23/05/2014.
//
//

#ifndef _ARUPDATER_DOWNLOADER_PRIVATE_H_
#define _ARUPDATER_DOWNLOADER_PRIVATE_H_

#include <libARUpdater/ARUPDATER_Error.h>
#include <libARUpdater/ARUPDATER_Downloader.h>
#include <libARSAL/ARSAL_Mutex.h>
#include "ARUPDATER_DownloadInformation.h"

struct ARUPDATER_Downloader_t
{
    char *rootFolder;
    
    eARUPDATER_Downloader_Platforms appPlatform;
    char *appVersion;
    
    void *downloadArg;
    void *progressArg;
    void *completionArg;
    
    int isRunning;
    int isCanceled;
    
    int updateHasBeenChecked;
    ARUPDATER_DownloadInformation_t **downloadInfos;
    
    ARSAL_MD5_Manager_t *md5Manager;
    
    ARSAL_Mutex_t requestLock;
    ARSAL_Mutex_t downloadLock;
    ARUTILS_Http_Connection_t *requestConnection;
    ARUTILS_Http_Connection_t *downloadConnection;
    
    ARUPDATER_Downloader_ShouldDownloadPlfCallback_t shouldDownloadCallback;
    ARUPDATER_Downloader_PlfDownloadProgressCallback_t plfDownloadProgressCallback;
    ARUPDATER_Downloader_PlfDownloadCompletionCallback_t plfDownloadCompletionCallback;
};

char *ARUPDATER_Downloader_GetPlatformName(eARUPDATER_Downloader_Platforms platform);

#endif
