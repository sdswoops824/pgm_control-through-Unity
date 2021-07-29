using Leap.Unity.Interaction;
using UnityEngine;
using System;
using System.IO;
using System.Collections;
using System.IO.Ports;
using System.Collections.Generic;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using Leap.Unity;

[RequireComponent(typeof(InteractionBehaviour))]
public class pgmbehaviour : MonoBehaviour
{  
    Renderer rend;
    Color white = Color.white;
    Color gray = Color.gray;
    

    private InteractionBehaviour _intObj; 
    public SerialPort myserial = new SerialPort("COM3", 115200);
    
    public float timer = 0.0f;
    public int Timesleft = 50;
    private float[] timeinstants = new float[1000];
    public int count = 0;

    public AudioClip magnetic;
    public AudioSource magneticsource;

    void Start()
    {
       _intObj = GetComponent<InteractionBehaviour>();
        timeinstants[0] = 0;
        magneticsource.clip = magnetic;
        rend = GetComponent<Renderer>();
        white.a = 0.2f;
        gray.a = 0.2f;
    }    

    void Update()
    {        
        timer += Time.deltaTime;      

        if (_intObj.isPrimaryHovered == true && gameObject.name == "repulsive")
        {
            count += 1;
            if (count == 999)
            {
                count = 1;
            }
            timeinstants[count] = timer;

            if (timeinstants[count] - timeinstants[count - 1] > 0.5)
            {
                if (myserial.IsOpen == false)
                {
                    Timesleft -= 1;
                    myserial.Open();
                    myserial.Write("3");
                }
                else
                {
                    Timesleft -= 1;
                    myserial.Write("3");
                }

                print("repeling");
            }
        }

        if (_intObj.isPrimaryHovered == true && gameObject.name == "pass through")
        {           
            count += 1;
            if (count == 999)
            {
                count = 1;
            }
            timeinstants[count] = timer;

            if (timeinstants[count] - timeinstants[count - 1] > 0.5)
            {
                magneticsource.Play();
                rend.material.color = gray;
                if (myserial.IsOpen == false)
                {
                    Timesleft -= 1;
                    myserial.Open();
                    myserial.Write("4");
                }
                else
                {
                    Timesleft -= 1;
                    myserial.Write("4");
                }

                print("passing through1");
            }
            else
            {                
                rend.material.color = white;
            }
        }
        else
        {
            magneticsource.Stop();
        }

       if (_intObj.isPrimaryHovered == true && gameObject.name == "soft")
        {
            count += 1;
            if (count == 999)
            {
                count = 1;
            }
            timeinstants[count] = timer;

            if (timeinstants[count] - timeinstants[count - 1] > 0.5)
            {
                if (myserial.IsOpen == false)
                {
                    Timesleft -= 1;
                    myserial.Open();
                    myserial.Write("1");
                }
                else
                {
                    Timesleft -= 1;
                    myserial.Write("1");
                }

                print("soft");
            }
        }

        if (_intObj.isPrimaryHovered == true && gameObject.name == "hard")
        {
            count += 1;
            if (count == 999)
            {
                count = 1;
            }
            timeinstants[count] = timer;

            if (timeinstants[count] - timeinstants[count - 1] > 0.5)
            {
                if (myserial.IsOpen == false)
                {
                    Timesleft -= 1;
                    myserial.Open();
                    myserial.Write("2");
                }
                else
                {
                    Timesleft -= 1;
                    myserial.Write("2");
                }

                print("hard");
            }
        }
    }


   /* void OnTriggerEnter(Collider other)
    {
        if (gameObject.name == "soft")
        {
            count += 1;
            if (count == 999)
            {
                count = 1;
            }
            timeinstants[count] = timer;

            if (timeinstants[count] - timeinstants[count - 1] > 2)
            {
                if (myserial.IsOpen == false)
                {
                    Timesleft -= 1;
                    myserial.Open();
                    myserial.Write("1");
                }
                else
                {
                    Timesleft -= 1;
                    myserial.Write("1");
                }

                print("soft");
            }
        }

        if (gameObject.name == "hard")
        {
            count += 1;
            if (count == 999)
            {
                count = 1;
            }
            timeinstants[count] = timer;

            if (timeinstants[count] - timeinstants[count - 1] > 2)
            {
                if (myserial.IsOpen == false)
                {
                    Timesleft -= 1;
                    myserial.Open();
                    myserial.Write("2");
                }
                else
                {
                    Timesleft -= 1;
                    myserial.Write("2");
                }

                print("hard");
            }
        }

        if (gameObject.name == "repulsive")
        {
            count += 1;
            if (count == 999)
            {
                count = 1;
            }
            timeinstants[count] = timer;

            if (timeinstants[count] - timeinstants[count - 1] > 2)
            {
                if (myserial.IsOpen == false)
                {
                    Timesleft -= 1;
                    myserial.Open();
                    myserial.Write("3");
                }
                else
                {
                    Timesleft -= 1;
                    myserial.Write("3");
                }

                print("repulsive");
            }
        }

    }*/

    void OnApplicationQuit()
    {
        if (myserial.IsOpen == true)
        {
            myserial.Write("0");
            myserial.Close();
        }
        
    }



    
}

