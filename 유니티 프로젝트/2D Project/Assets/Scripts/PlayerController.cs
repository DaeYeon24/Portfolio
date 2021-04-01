using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    Rigidbody2D playerRigidbody;
    SpriteRenderer spriteRenderer;
    Animator playerAnimator;
    // Start is called before the first frame update
    void Awake()
    {
        playerRigidbody = GetComponent<Rigidbody2D>();
        spriteRenderer = GetComponent<SpriteRenderer>();
        playerAnimator = GetComponent<Animator>();
    }

    void Update()
    {
        if (Input.GetButton("Horizontal"))
            spriteRenderer.flipX = Input.GetAxisRaw("Horizontal") == -1;

        if (playerRigidbody.velocity.x == 0)
            playerAnimator.SetBool("isRun", false);
        else
            playerAnimator.SetBool("isRun", true);
    }
    void FixedUpdate()
    {
        float xInput = Input.GetAxisRaw("Horizontal");

        playerRigidbody.velocity = new Vector2(xInput, 0) * 150f * Time.deltaTime;
        //playerRigidbody.AddForce(new Vector2(xInput, 0), ForceMode2D.Impulse);
    }
}
