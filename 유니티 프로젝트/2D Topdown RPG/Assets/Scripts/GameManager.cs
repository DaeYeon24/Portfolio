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
    TalkManager talkManager;
    int talkIndex;
    public static GameManager instance
    {
        get
        {
            if (m_instance == null)
                m_instance = FindObjectOfType<GameManager>();
            return m_instance;
        }
    }

    void Awake()
    {
        talkManager = FindObjectOfType<TalkManager>();
        isInteraction = false;
        talkIndex = 0;
    }
     
    public void Interaction(GameObject obj)
    {
        isInteraction = true;
        ObjectData objectData = obj.GetComponent<ObjectData>();
        Talk(objectData);

        Panel.SetActive(isInteraction);
    }

    void Talk(ObjectData objData)
    {
        string talkString = talkManager.GetTalk(objData.id, talkIndex);

        if (talkString == null)
        {
            isInteraction = false;
            talkIndex = 0;
            return;
        }

        if(objData.isNPC)
            text.text = talkString;
        else
            text.text = talkString;

        talkIndex++;
    }
}
