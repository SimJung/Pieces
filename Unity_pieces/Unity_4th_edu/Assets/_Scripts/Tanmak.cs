using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tanmak : MonoBehaviour {
    
	private int k = 0;
    public GameObject bullet;

    void Start()
    {
        Destroy(gameObject, 10f);
    }

    void Update () {
            Instantiate(bullet, new Vector3(0, 0, 0), Quaternion.Euler(0, k, 0));
            k++;
	}
}
