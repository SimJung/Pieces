using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class move : MonoBehaviour {

    public GameObject camera;
    private float speed = 0.05f;



	void Start () {
		
	}
	
	void Update () {
        if(Input.GetKey(KeyCode.D))
        {
            gameObject.transform.Translate(speed, 0, 0);
        }

        if(Input.GetKey(KeyCode.A))
        {
            gameObject.transform.Translate(-speed, 0, 0);
        }

        if (Input.GetKey(KeyCode.W))
        {
            gameObject.transform.Translate(0, 0, speed);
        }

        if (Input.GetKey(KeyCode.S))
        {
            gameObject.transform.Translate(0, 0, -speed);
        }


        camera.transform.Rotate(-Input.GetAxis("Mouse Y"), 0f, 0f);
        gameObject.transform.Rotate(0, Input.GetAxis("Mouse X"), 0);


        if(Input.GetKeyDown(KeyCode.Space))
            GetComponent<Rigidbody>().AddForce(0, 50, 0, ForceMode.Impulse);
    }
}
