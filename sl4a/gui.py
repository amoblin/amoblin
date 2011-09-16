import android

droid = android.Android()

droid.webViewShow('file:///sdcard/sl4a/scripts/gui.html')
while True:
    number = droid.eventWaitFor('number').result
    droid.makeToast(number['data'])
