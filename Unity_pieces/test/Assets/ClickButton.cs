using System.Collections;
using System.Collections.Generic;
using UnityEngine.SceneManagement;
using UnityEngine;

public class ClickButton : MonoBehaviour {

	public void Click()
    {
        SceneManager.LoadScene(1);

    }
}
