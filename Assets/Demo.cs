//C#
using UnityEngine;
using System.Collections;

public class Demo : MonoBehaviour {

	void OnGUI () {
		int ratio = ((int)Screen.width / 480)+1;
		GUI.Box(new Rect(10*ratio,10*ratio,100*ratio,40*ratio), "");
		if(GUI.Button(new Rect(20*ratio,20*ratio,80*ratio,20*ratio), "Visit")) {
			RequestReview.remind();
		}
	}
	
}
