using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlatformSpawner : MonoBehaviour
{
    public GameObject platformPrefab;
    GameObject[] platforms;
    int platformCount;
    int currentIndex;
    float spawnTimeMin;
    float spawnTimeMax;
    float spawnTimeGap;
    float lastSpawnTime;
    float createMin;
    float createMax;
    float[] createZ;
    Vector3 poolPos;

    void Awake()
    {
        platformCount = 3;
        currentIndex = 0;
        spawnTimeMin = 1f;
        spawnTimeMax = 3f;
        spawnTimeGap = 0;
        lastSpawnTime = 0;
        createMin = -3;
        createMax = 3;
        createZ = new float[3];
        poolPos = new Vector3(0, -10, 0);
        platforms = new GameObject[platformCount];

        for(int i = 0; i < platformCount; i++)
        {
            platforms[i] = Instantiate(platformPrefab, poolPos, Quaternion.identity);
            createZ[i] = 0f;
        }
    }

    void Update()
    {
        if (!UIManager.getInstance.powerOn || platforms[currentIndex].GetComponent<Platform>().isSpawn)
            return;

        if (Time.time >= lastSpawnTime + spawnTimeGap)
        {
            lastSpawnTime = Time.time;

            spawnTimeGap = Random.Range(spawnTimeMin, spawnTimeMax);

            float xPos = Random.Range(createMin, createMax);
            float yPos = Random.Range(createMin, createMax);

            platforms[currentIndex].SetActive(false);
            platforms[currentIndex].SetActive(true);

            int prevIndex = currentIndex - 1;
            if (prevIndex < 0)
                prevIndex = 2;

            createZ[currentIndex] = platforms[prevIndex].transform.position.z + 10;
            platforms[currentIndex].transform.position = new Vector3(xPos, yPos, createZ[currentIndex++]);

            if (currentIndex >= platformCount)
                currentIndex = 0;
        }
    }
}
