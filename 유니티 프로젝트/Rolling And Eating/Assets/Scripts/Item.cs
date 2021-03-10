using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour
{
    int score;

    void OnEnable()
    {
        score = Random.Range(1, 100);
    }

    void Update()
    {
        transform.Rotate(Vector3.up * 50 * Time.deltaTime, Space.World);
    }

    void OnTriggerEnter(Collider other)
    {
        if(other.tag == "Player")
        {
            other.GetComponent<AudioSource>().Play();
            GameManager.getInstance.AddScore(score);
            gameObject.SetActive(false);
        }
    }
}
//f