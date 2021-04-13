using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerCtrl : MonoBehaviour
{
    Rigidbody2D rigid;
    Animator anim;
    Vector3 frontVec;
    GameObject scanObject;
    float xInput;
    float zInput;
    int speed;
    bool isHorizonMove;

    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>();
        anim = GetComponent<Animator>();
        speed = 10;
    }

    void Update()
    {
        if(!GameManager.instance.isInteraction)
        {
            xInput = Input.GetAxisRaw("Horizontal");
            zInput = Input.GetAxisRaw("Vertical");

            if (Input.GetButtonDown("Horizontal"))
                isHorizonMove = true;
            else if (Input.GetButtonDown("Vertical"))
                isHorizonMove = false;
            else if (Input.GetButtonUp("Horizontal") || Input.GetButtonUp("Vertical"))
                isHorizonMove = xInput != 0;

            if (Input.GetButtonDown("Vertical") && zInput < 0)
                frontVec = Vector3.down;
            else if (Input.GetButtonDown("Vertical") && zInput > 0)
                frontVec = Vector3.up;
            else if (Input.GetButtonDown("Horizontal") && xInput < 0)
                frontVec = Vector3.left;
            else if (Input.GetButtonDown("Horizontal") && xInput > 0)
                frontVec = Vector3.right;
        }
        // 이동키를 누르고 있는 순간의 애니메이션 설정 여러키를 눌렀을때 애니메이션의 대응
        if (anim.GetInteger("xAxisRaw") != (int)xInput)
        {
            anim.SetBool("keyChange", true);
            anim.SetInteger("xAxisRaw", (int)xInput);
        }
        else if (anim.GetInteger("zAxisRaw") != (int)zInput)
        {
            anim.SetBool("keyChange", true);
            anim.SetInteger("zAxisRaw", (int)zInput);
        }
        else
            anim.SetBool("keyChange", false);
        // 상호작용
        if (Input.GetKeyDown(KeyCode.Space) && scanObject != null)
            GameManager.instance.Interaction(scanObject);
    }

    void FixedUpdate()
    {
        // 대각선 이동 방지
        Vector2 moveVec = isHorizonMove ? new Vector2(xInput, 0) : new Vector2(0, zInput);
        // 결정된 방향 이동
        rigid.velocity = moveVec * speed;

        Debug.DrawRay(rigid.position, frontVec * 0.7f, new Color(1, 0, 0));
        RaycastHit2D scanRay = Physics2D.Raycast(rigid.position, frontVec, 0.7f, LayerMask.GetMask("Object"));

        if (scanRay.collider != null)
            scanObject = scanRay.collider.gameObject;
        else
            scanObject = null;
    }
}
