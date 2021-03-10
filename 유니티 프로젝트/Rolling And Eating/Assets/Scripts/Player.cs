using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    Rigidbody playerRigidbody;
    float jumpForce, speed;
    int jumpCount;
    bool readyToJump;

    void Awake()
    {
        playerRigidbody = GetComponent<Rigidbody>();
        jumpForce = 45f;
        speed = 30f;
        jumpCount = 0;
        readyToJump = false;
    }

    void FixedUpdate()
    {
        if (!UIManager.getInstance.powerOn)
            return;
        float xInput = Input.GetAxisRaw("Horizontal") * speed;
        float zInput = Input.GetAxisRaw("Vertical") * speed;
        playerRigidbody.AddForce(new Vector3(xInput * Time.deltaTime, 0, zInput * Time.deltaTime), ForceMode.Impulse);
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
            readyToJump = true;
            jumpCount = 0;
        }
    }
}
