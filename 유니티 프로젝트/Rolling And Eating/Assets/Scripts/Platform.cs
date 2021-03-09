using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Platform : MonoBehaviour
{
    public GameObject[] items;
    public bool isSpawn;
    Floor floor;

    void Awake()
    {
        floor = FindObjectOfType<Floor>();
    }

    private void Start()
    {
        isSpawn = false;
    }

    void OnEnable()
    {

        isSpawn = true;
        for(int i = 0; i < items.Length; i ++)
        {
            if (Random.Range(1, 3) == 1)
                items[i].SetActive(true);
            else
                items[i].SetActive(false);
        }
    }

    void Update()
    {
        if (floor.isGone)
            StartCoroutine(Disable());
    }

    private IEnumerator Disable()
    {
        yield return new WaitForSeconds(3f);
        gameObject.SetActive(false);
    }

    void OnDisable()
    {
        isSpawn = false;
    }
}
