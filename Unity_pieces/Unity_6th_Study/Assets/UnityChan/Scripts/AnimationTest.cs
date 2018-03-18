using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class AnimationTest : MonoBehaviour {

    private int score = 0;
    private Animator anim;
    public Text txt;

	// Use this for initialization
	void Start () {

        anim = GetComponent<Animator>();

	}
	
	// Update is called once per frame
	void Update () {

        if (Input.GetKey(KeyCode.W))
        {
            transform.rotation = Quaternion.Euler(0, 0, 0);
            transform.Translate(0, 0, 0.1f);
            anim.SetBool("RUN", true);
        }
        else if (Input.GetKey(KeyCode.A) && transform.position.x >= -9)
        {
            transform.rotation = Quaternion.Euler(0, -90, 0);
            transform.Translate(0, 0, 0.1f);
            anim.SetBool("RUN", true);
        }
        else if (Input.GetKey(KeyCode.S))
        {
            transform.rotation = Quaternion.Euler(0, 180, 0);
            transform.Translate(0, 0, 0.1f);
            anim.SetBool("RUN", true);
        }
        else if (Input.GetKey(KeyCode.D) && transform.position.x <= 9)
        {
            transform.rotation = Quaternion.Euler(0, 90, 0);
            transform.Translate(0, 0, 0.1f);
            anim.SetBool("RUN", true);
        }
        else
            anim.SetBool("RUN", false);


        txt.text = "SCORE: " + score;

    }

    private void OnTriggerEnter(Collider collision)
    {
        if (collision.transform.tag == "Bonus")
        {
            anim.SetTrigger("GOOD");
            score++;
        }

        if (collision.transform.tag == "Enemy")
        {
            anim.SetTrigger("BAD");
            if(score > 0)
                score--;
        }
    }

}
