using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Floor : MonoBehaviour
{
    public bool isGone;

    void OnEnable()
    {
        isGone = false;
    }

    void OnCollisionExit(Collision collision)
    {
        if (collision.gameObject.tag == "Player")
            isGone = true;
    }
}
