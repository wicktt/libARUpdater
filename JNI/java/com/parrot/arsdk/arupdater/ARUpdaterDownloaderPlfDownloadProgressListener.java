
package com.parrot.arsdk.arupdater;

public interface ARUpdaterDownloaderPlfDownloadProgressListener
{
	/**
     * Give the PLF download progress
     * @param arg Object Listener arg
     * @param progress the progress in percent
     * @return void
     */
	void onPlfDownloadProgress(Object arg, int progress);
}