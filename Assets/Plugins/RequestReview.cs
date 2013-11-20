using UnityEngine;
using System.Runtime.InteropServices;
public class RequestReview {
    [DllImport("__Internal")]
    private static extern void remind_ ();
    public static void remind () {
        if (Application.platform != RuntimePlatform.OSXEditor) {
            remind_();
        }
    }
}
