using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move : MonoBehaviour {

    private Rigidbody rgbody;

    void Start()
    {
        rgbody = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update () {
        if (Input.GetKey(KeyCode.W))
            rgbody.AddForce(0, 0, 1.0f, ForceMode.Force);
        if (Input.GetKey(KeyCode.S))
            rgbody.AddForce(0, 0, -1.0f, ForceMode.Force);
        if (Input.GetKey(KeyCode.A))
            rgbody.AddForce(-1.0f, 0, 0, ForceMode.Force);
        if (Input.GetKey(KeyCode.D))
            rgbody.AddForce(1.0f, 0, 0, ForceMode.Force);

        Debug.Log(rgbody.velocity);
    }


    private void OnTriggerEnter(Collider other)
    {
        if (other.transform.tag == "boost")
            rgbody.AddForce(0.2f * rgbody.velocity, ForceMode.Impulse);

        if (other.transform.tag == "enemy")
            rgbody.AddForce(0.2f * -rgbody.velocity, ForceMode.Impulse);
    }
}
