using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    Rigidbody playerRigidbody;
    public int score; // UI 만들면 옮기기
    public bool isGameClear; // 마찬가지 고려해보자

    float jumpForce;
    float speed;
    int jumpCount;
    bool isFloor;

    void Awake()
    {
        playerRigidbody = GetComponent<Rigidbody>();
        score = 0;
        jumpForce = 30f;
        speed = 30f;
        jumpCount = 0;
        isFloor = false;
        isGameClear = false;
    }

    void FixedUpdate()
    {
        float xInput = Input.GetAxisRaw("Horizontal") * speed;
        float zInput = Input.GetAxisRaw("Vertical") * speed;
        playerRigidbody.AddForce(new Vector3(xInput * Time.deltaTime, 0, zInput * Time.deltaTime), ForceMode.Impulse);

    }

    void Update()
    {
        if (Input.GetButtonDown("Jump") && jumpCount < 2)
        {
            jumpCount++;
            playerRigidbody.velocity = new Vector3(playerRigidbody.velocity.x, 0, playerRigidbody.velocity.z);
            playerRigidbody.AddForce(new Vector3(0, jumpForce, 0), ForceMode.Impulse);
        }
        else if (Input.GetButtonUp("Jump") && playerRigidbody.velocity.y > 0)
            playerRigidbody.velocity = playerRigidbody.velocity * 0.5f;
    }

    void OnCollisionEnter(Collision collision)
    {
        if(collision.gameObject.tag == "Floor")
        {
            isFloor = true;
            jumpCount = 0;
        }
    }

    void OnTriggerEnter(Collider other)
    {
        if(other.tag == "Finish")
            isGameClear = true;
    }
}
