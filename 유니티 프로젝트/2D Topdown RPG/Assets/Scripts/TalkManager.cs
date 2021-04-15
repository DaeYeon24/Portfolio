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
        talkData.Add(100, new string[] { "�̰� �������ڴ�." });
        talkData.Add(101, new string[] { "������ ����ߴ� å���̴�" });
        talkData.Add(102, new string[] { "�ܴ��� ������ �ֳ�" });
        talkData.Add(1000, new string[] { "�ȳ�?", "�� ���� ó�� �Ա���?" });
        talkData.Add(1001, new string[] { "�ʴ� ������?", "���� Luna��� ��" });
    }

    public string GetTalk(int id, int talkIndex)
    {
        if (talkIndex == talkData[id].Length)
            return null;
        else
            return talkData[id][talkIndex];
    }

}
