using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    private Rigidbody playerRigidbody;
    public float speed = 15f;

    void Start()
    {
        playerRigidbody = GetComponent<Rigidbody>();
    }
    
    void Update()
    {
        float xInput = Input.GetAxis("Horizontal");
        float zInput = Input.GetAxis("Vertical");

        float xSpeed = xInput * speed;
        float zSpeed = zInput * speed;

        Vector3 newVelocity = new Vector3(xSpeed, 0f, zSpeed);

        playerRigidbody.velocity = newVelocity;

/*        if(Input.GetKey(KeyCode.UpArrow))
            playerRigidbody.AddForce(0f, 0f, speed);
        if (Input.GetKey(KeyCode.DownArrow))
            playerRigidbody.AddForce(0f, 0f, -speed);
        if (Input.GetKey(KeyCode.RightArrow))
            playerRigidbody.AddForce(speed, 0f, 0f);
        if (Input.GetKey(KeyCode.LeftArrow))
            playerRigidbody.AddForce(-speed, 0f, 0f);
*/
    }

    public void Die()
    {
        // 본 게임 오브젝트 비활성화
        gameObject.SetActive(false);
        // 씬에 존재하는 매니저 호출
        GameManager gameManager = FindObjectOfType<GameManager>();
        // 호출된 매니저 EndGame() 실행
        gameManager.EndGame();
    }
}
