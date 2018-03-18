using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Duplicate : MonoBehaviour {

    public GameObject good_p;
    public GameObject bad_p;

    void Update()
    {
        if(Random.Range(0,32) == 7)
        {
            Instantiate(good_p, new Vector3(Random.Range(-2, 3) * 3.5f, 1.5f, 48.25f), Quaternion.Euler(0, 0, 180));
        }

        if (Random.Range(0, 32) == 8)
        {
            Instantiate(bad_p, new Vector3(Random.Range(-2, 3) * 3.5f, 1.5f, 48.25f), Quaternion.Euler(0, 0, 180));
        }
    }

}
