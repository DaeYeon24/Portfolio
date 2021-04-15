using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TalkManager : MonoBehaviour
{
    Dictionary<int, string[]> talkData;

    void Awake()
    {
        talkData = new Dictionary<int, string[]>();
        GenerateData();
    }

    void GenerateData()
    {
        talkData.Add(100, new string[] { "이건 나무상자다." });
        talkData.Add(101, new string[] { "누군가 사용했던 책상이다" });
        talkData.Add(102, new string[] { "단단한 바위가 있네" });
        talkData.Add(1000, new string[] { "안녕?", "이 곳에 처음 왔구나?" });
        talkData.Add(1001, new string[] { "너는 누구니?", "나는 Luna라고 해" });
    }

    public string GetTalk(int id, int talkIndex)
    {
        if (talkIndex == talkData[id].Length)
            return null;
        else
            return talkData[id][talkIndex];
    }

}
