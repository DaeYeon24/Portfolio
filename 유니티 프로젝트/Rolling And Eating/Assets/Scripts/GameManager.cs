using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    Player player;
    // Start is called before the first frame update
    void Awake()
    {
        player = FindObjectOfType<Player>();
    }

    // Update is called once per frame
    void LateUpdate()
    {
        if (player.isGameClear)
            SceneManager.LoadScene("SampleScene");
    }
}
