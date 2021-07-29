using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class scenemanager : MonoBehaviour
{
    //public TextMesh time;
    public float timer = 30.0f;
    private int limit = 0;
    // Start is called before the first frame update
    void Start()
    {
       
    }

    // Update is called once per frame
    void Update()
    {
        Scene scene = SceneManager.GetActiveScene();
        timer -= Time.deltaTime;
       // time.text = timer.ToString() + " Seconds to go";
        if (timer < limit && scene.name == "scene1")
        {
            SceneManager.LoadScene("scene2");
        }

        else if(timer < limit && scene.name == "scene2")
        {
            SceneManager.LoadScene("scene3");
        }

        else if (timer < limit && scene.name == "scene3")
        {
            SceneManager.LoadScene("scene4");
        }

        else if (timer < limit && scene.name == "scene4")
        {
            SceneManager.LoadScene("scene1");
        }
    }
}
