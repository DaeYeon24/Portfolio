using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public GameObject Panel;
    public Text text;
    //public GameObject scanObject;
    static GameManager m_instance;
    public bool isInteraction { get; private set; }
    public static GameManager instance
    {
        get
        {
            if (m_instance == null)
                m_instance = FindObjectOfType<GameManager>();
            return m_instance;
        }
    }

    public void Interaction(GameObject obj)
    {
        if (isInteraction)
            isInteraction = false;
        else
        {
            isInteraction = true;
            text.text = "이것은 " + obj.name + "라고 한다";
        }
        Panel.SetActive(isInteraction);
    }
}
