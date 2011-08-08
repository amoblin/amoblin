#_*_ coding:utf-8 _*_
import android,time
Droid = android.Android()
if Droid.mediaIsPlaying():
    Droid.mediaPlayPause()
else:
    Droid.mediaPlay("file:///sdcard/Music/小小.mp3")
    Droid.setMediaVolume(99)
    time.sleep(600)
