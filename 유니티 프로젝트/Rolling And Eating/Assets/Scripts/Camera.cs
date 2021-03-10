using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Camera : MonoBehaviour
{
    Transform playerTransform;
    Vector3 offset;
    // Start is called before the first frame update
    void Awake()
    {
        playerTransform = FindObjectOfType<Player>().transform;
        offset = transform.position - playerTransform.position;
    }

    void LateUpdate()
    {
        transform.position = playerTransform.position + offset;
    }
}
// f