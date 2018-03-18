using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Fire : MonoBehaviour {

    void Update()
    {
        gameObject.transform.Translate(0, 0, 1);
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.transform.tag == "enemy")
        {
            Destroy(other.gameObject);
            Destroy(gameObject);
        }
            
    }
}
