# result = 5>10
# default = True
# print(f"结果是：{result}，默认是：{default}")

# age = int(input("请输入年龄："))
# if age >= 18:
#     print(f"你{age}岁，已成年")
# else:
#     print(f"你{age}岁，未成年")
    
# money = int(input("你的预算多少："))
# if money >= 100:
#     print(f"预算{money}，太贵了")
# elif money <100 and money >= 50:
#     print(f"预算{money}，还行")
# elif money <50 and money >= 0:
#     print(f"预算{money}，有点低")

# import random
# num = random.randint(1,10)
# print(num)

height = int(input("你的身高多少："))
vip = input("是否是VIP : ")
if height>=180:
    print("超高")
    if vip == "是":
        print("免费")
    else:
        print("全价票")
elif height<180 and height>=150:
    print("正常")
    if vip == "是":
        print("免费")
    else:
        print("半价票")
else:
    print("免费")