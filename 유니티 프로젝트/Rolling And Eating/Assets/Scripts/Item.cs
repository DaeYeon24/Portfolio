using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour
{
    void Update()
    {
        transform.Rotate(Vector3.up * 50 * Time.deltaTime, Space.World);
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.tag == "Player")
        {
            other.GetComponent<Player>().score += 100; // UI 만들면 UI로 옮기기
            other.GetComponent<Player>().GetComponent<AudioSource>().Play();
            gameObject.SetActive(false);
        }
    }
}
