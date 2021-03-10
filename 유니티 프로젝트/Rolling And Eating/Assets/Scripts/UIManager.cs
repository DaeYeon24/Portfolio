using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class UIManager : MonoBehaviour
{
    private static UIManager instance;
    public GameObject mainUI;
    public GameObject GameOverUI;
    public Text scoreText;
    public Text bestScoreText;
    public bool powerOn;

    void Awake()
    {
        powerOn = false;
        if (instance == null)
        {
            instance = this;
            DontDestroyOnLoad(this.gameObject);
        }
        else
            Destroy(this.gameObject);
    }

    //게임 매니저 인스턴스에 접근할 수 있는 프로퍼티. static이므로 다른 클래스에서 맘껏 호출할 수 있다.
    public static UIManager getInstance
    {
        get
        {
            if (instance == null)
                return null;
            return instance;
        }
    }

    public void UpdateScoreText(int newscore)
    {
        scoreText.text = "SCORE : " + newscore;
    }

    public void UpdateBestScoreText(int newscore)
    {
        bestScoreText.text = "Best Score : " + newscore;
    }

    public void SetActiveGameOverUI(bool active)
    {
        GameOverUI.SetActive(true);
    }

    public void GameStart()
    {
        powerOn = true;
        PlayerPrefs.DeleteAll();
        mainUI.SetActive(false);
    }

    public void GameRestart()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        if (powerOn)
            mainUI.SetActive(false);
        GameOverUI.SetActive(false);
        UpdateScoreText(0);
    }
}
