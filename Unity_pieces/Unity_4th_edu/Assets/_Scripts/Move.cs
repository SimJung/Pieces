using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move : MonoBehaviour {

    public GameObject camera1;
    public Transform parent;
    public GameObject bullet;
    
	
	// Update is called once per frame
	void Update () {
        if (Input.GetKey(KeyCode.W))
            gameObject.transform.Translate(0, 0, 0.1f);

        if (Input.GetKey(KeyCode.S))
            gameObject.transform.Translate(0, 0, -0.1f);

        if (Input.GetKey(KeyCode.A))
            gameObject.transform.Translate(-0.1f, 0, 0);

        if (Input.GetKey(KeyCode.D))
            gameObject.transform.Translate(0.1f, 0, 0);

        camera1.transform.Rotate(-Input.GetAxis("Mouse Y"), 0, 0);
        gameObject.transform.Rotate(0, Input.GetAxis("Mouse X"), 0);

        if(Input.GetMouseButtonDown(0))
        {
            GameObject obj1 = Instantiate(bullet, parent.position, gameObject.transform.rotation);

            obj1.GetComponent<Rigidbody>().AddForce(0, 0, 200, ForceMode.Impulse);

            Destroy(obj1, 10f);
        }
    }
}
