using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerCtrl : MonoBehaviour {

    public float speed = 0.5f;
    private Transform playerTf;
    private Vector3 playerPos;

    void Awake()
    {
        playerTf = transform;
    }

    void Start()
    {
        StartCoroutine("MoveTheBall");
    }

    IEnumerator MoveTheBall()
    {
        playerPos = playerTf.position;

        while (true)
        {
            yield return new WaitForSeconds(0.02f);
            playerPos.x += speed;
            playerTf.position = playerPos;
        }
    }
}
