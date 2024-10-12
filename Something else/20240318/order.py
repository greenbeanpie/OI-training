# encoding=utf-8

import requests, json, time, sys, threading,base64
from Crypto.Cipher import AES

url = "http://172.16.28.15:4132"
header = {
	"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36 Edg/122.0.0.0",
	"Cookie": "",
}

tmp = requests.get("http://172.16.28.15:4132/wlhs/index", headers=header)
header["Cookie"] = "zyxk-zzzd=" + tmp.cookies.values()[0]
cur_time = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())

from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
import base64

'''
AES工具类：使用ECB模式加密，pkcs7格式的padding

为便于理解，我把每个步骤对应的代码单独成行了
'''
class AESUtil:
    # 使用ECB模式加密
    MODE = AES.MODE_ECB
    # 使用默认的pkcs7 padding
    PAD_STYLE = 'pkcs7'
    ENCODING = 'UTF-8'
   
    # key长度只能为16或24或32，分别对应AES-128、AES-192、AES-256
    @staticmethod
    def encrypt(plaintext: str, key: str) -> str:
        # 将密钥编码为UTF-8格式的bytes
        key_bytes = key.encode(AESUtil.ENCODING)
        # 创建AES对象
        cipher = AES.new(key_bytes, AESUtil.MODE)
        # 将明文编码为UTF-8格式的bytes
        plaintext_bytes = plaintext.encode(AESUtil.ENCODING)
        # 为编码后的明文添加padding
        plaintext_bytes_padded = pad(plaintext_bytes, AES.block_size, AESUtil.PAD_STYLE)
        # 执行加密
        ciphertext_bytes = cipher.encrypt(plaintext_bytes_padded)
        # 将加密后的bytes进行base64编码
        # 注意：不能用encodebytes！否则会每76个字符增加一个换行符，见：https://docs.python.org/zh-cn/3/library/base64.html
        ciphertext_base64_bytes = base64.b64encode(ciphertext_bytes) 
        # 将base64编码过的bytes，解码为Python中使用的字符串类型（即unicode字符串）
        ciphertext = ciphertext_base64_bytes.decode(AESUtil.ENCODING)
        return ciphertext

    @staticmethod
    def decrypt(ciphertext: str, key: str) -> str:
        # 将密钥编码为UTF-8格式的bytes
        key_bytes = key.encode(AESUtil.ENCODING)
        # 创建AES对象
        decrypter = AES.new(key_bytes, AESUtil.MODE)
        # 将密文编码为UTF-8格式的（同时也是base64编码的）bytes
        ciphertext_base64_bytes = ciphertext.encode(AESUtil.ENCODING)
        # 将base64编码的bytes，解码为原始的密文bytes
        ciphertext_bytes = base64.b64decode(ciphertext_base64_bytes)
        # 解码为明文
        plaintext_bytes_padded = decrypter.decrypt(ciphertext_bytes)
        # 去掉Padding
        plaintext_bytes = unpad(plaintext_bytes_padded, AES.block_size, AESUtil.PAD_STYLE)
        # 将UTF-8格式编码的明文bytes，解码为Python中的字符串类型（即unicode字符串）
        plaintext = plaintext_bytes.decode(AESUtil.ENCODING)
        return plaintext
class meal:
	def __init__(self) -> None:
		self.number = 0
		self.content = ""
		self.status = ""


def login(username=28941,password=111111):
	url1 = url + "/102/login/system/card/r.do"
	key = "KPBCfL93xmPSgaA9"
	password=AESUtil.encrypt(str(password),key)
	content = {
		"username": str(username),
		"type": "1",
		"password": "sB1TSVg6Zq7QdcbY9WBonw==",
		"tenantCode": "wlhs",
	}
	response = requests.post(url1, params=content, headers=header)
	data = json.loads(response.text)


def query_today():
	url2 = url + "/117/portal/saleOrder/l.do?t=0.3300768256632223"
	param = {
		"pageNow": 1,
		"startSaleDate": "2024-03-17 00:00:00",
		"endSaleDate": "2024-03-17 23:59:59",
		"pageSize": 10,
		"orgId": "6cdda12c2bb0410e98a23b991febe17c",
	}
	response = requests.post(url2, params=param, headers=header)
	content = json.loads(response.text)
	meals = list()
	try:
		for i in content["result"]:
			if i["orderStatusName"] != "取消完成":
				temp = meal()
				temp.number = i["details"]["tccode"]
				temp.content = i["details"]["inventoryname"]
				temp.status = i["orderStatusName"]
				meals.append(temp)
	except:
		pass
	return meals
	example = """{
		"pageNow": 1,
		"pageSize": 10,
		"total": 2,
		"result": [
			{
				"saleOrderId": "94D5982E8CA748DEAE31CD9D2A182264",
				"orderCode": "2024031109000412",
				"username": "33617",
				"employeeNumber": "20230310",
				"phone": 0,
				"orderStatusName": "已提交",
				"payTypeName": "无",
				"orderAmount": 13,
				"payAmount": 13,
				"orderTime": "2024-03-11 09:04:12",
				"cancelTime": 0,
				"saleDate": 1710691200000,
				"saleTypeName": "晚餐",
				"pointName": "网上订餐销售点",
				"inventoryName": 0,
				"printStatusName": "未打印",
				"realname": "洪茉致",
				"deptName": "g2023(04)",
				"orgName": "学生餐厅",
				"channelTypeName": "网上订餐",
				"deliveryModeName": "留堂就餐",
				"deliveryAddr": 0,
				"terminalName": "自助终端",
				"orgId": "6cdda12c2bb0410e98a23b991febe17c",
				"userId": "0CAE9E47A0ED4184A3C7A49538D7443E",
				"orderStatus": 2,
				"payStatus": 0,
				"payStatusName": "未支付",
				"deliveryMode": 1,
				"channelType": -2,
				"payType": -1,
				"saleType": 11,
				"remark": 0,
				"print": 0,
				"payFlag": 1,
				"cancelFlag": 1,
				"vote": 0,
				"details": [
					{
						"saleOrderId": "94D5982E8CA748DEAE31CD9D2A182264",
						"inventoryId": "38712a3443ea473cbfd4b7c41a90897b",
						"inventoryName": "椒盐猪脚+毛豆肉咸菜+米饭[0318PM]",
						"photo": "cbbe599145c445639f0cf1b891d0d374",
						"saleNum": 1,
						"deliverGoodNum": 0,
						"unitPrice": 13,
						"status": 0,
						"statusName": "未退货",
						"saleAmount": 13,
						"saleOrderDetailId": "C4A47EF9CB344E459BDC818B24BD1101",
						"returnGoodsNum": 0,
						"dreturnGoodsNum": 0,
						"detailDiscount": 100,
						"star": 0,
						"voteContent": 0,
						"salePrice": 13.0,
						"discountMoney": 0.0,
						"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
						"pointName": "网上订餐销售点",
						"tccode": "【1号套餐】",
					}
				],
				"returnGoodsFlag": 0,
				"orderDiscount": 0,
				"nodeList": [
					{"orderStatus": -1, "statusFlag": 0},
					{"orderStatus": 6, "statusFlag": 0},
					{"orderStatus": 20, "statusFlag": 0},
				],
				"goodsCode": 0,
				"refundName": 0,
				"refundStatus": 0,
				"refundStatusName": 0,
				"refundMoney": 0,
				"refundRateType": 0,
				"refundRate": 0,
				"refundtime": 0,
				"terminalType": 1,
				"refundSettingTime": 0,
				"tableNumber": 0,
				"payAsnState": 0,
				"qrContent": 0,
				"payGroupType": 0,
				"pointInfoList": [
					{
						"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
						"pointName": "网上订餐销售点",
						"details": [
							{
								"saleOrderId": "94D5982E8CA748DEAE31CD9D2A182264",
								"inventoryId": "38712a3443ea473cbfd4b7c41a90897b",
								"inventoryName": "椒盐猪脚+毛豆肉咸菜+米饭[0318PM]",
								"photo": "cbbe599145c445639f0cf1b891d0d374",
								"saleNum": 1,
								"deliverGoodNum": 0,
								"unitPrice": 13,
								"status": 0,
								"statusName": "未退货",
								"saleAmount": 13,
								"saleOrderDetailId": "C4A47EF9CB344E459BDC818B24BD1101",
								"returnGoodsNum": 0,
								"dreturnGoodsNum": 0,
								"detailDiscount": 100,
								"star": 0,
								"voteContent": 0,
								"salePrice": 13.0,
								"discountMoney": 0.0,
								"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
								"pointName": "网上订餐销售点",
								"tccode": "【1号套餐】",
							}
						],
					}
				],
				"startTime": "13:31",
				"endTime": "18:30",
				"subDate": 1710119061000,
				"tenantId": 0,
				"canceler": 0,
				"manageFee": 0.0,
				"supplementName": 0,
				"supplementStatus": 0,
				"supplementSettingTime": 0,
				"supplementMoney": 0,
				"supplementRateType": 0,
				"supplementRate": 0,
				"supplementtime": 0,
			},
			{
				"saleOrderId": "6AA0C3A73B7D4CE591F05B9012A24B32",
				"orderCode": "2024030809001205",
				"username": "33617",
				"employeeNumber": "20230310",
				"phone": 0,
				"orderStatusName": "已提交",
				"payTypeName": "无",
				"orderAmount": 13,
				"payAmount": 13,
				"orderTime": "2024-03-08 09:17:53",
				"cancelTime": 0,
				"saleDate": 1710691200000,
				"saleTypeName": "中餐",
				"pointName": "网上订餐销售点",
				"inventoryName": 0,
				"printStatusName": "未打印",
				"realname": "洪茉致",
				"deptName": "g2023(04)",
				"orgName": "学生餐厅",
				"channelTypeName": "网上订餐",
				"deliveryModeName": "留堂就餐",
				"deliveryAddr": 0,
				"terminalName": "自助终端",
				"orgId": "6cdda12c2bb0410e98a23b991febe17c",
				"userId": "0CAE9E47A0ED4184A3C7A49538D7443E",
				"orderStatus": 2,
				"payStatus": 0,
				"payStatusName": "未支付",
				"deliveryMode": 1,
				"channelType": -2,
				"payType": -1,
				"saleType": 10,
				"remark": 0,
				"print": 0,
				"payFlag": 1,
				"cancelFlag": 1,
				"vote": 0,
				"details": [
					{
						"saleOrderId": "6AA0C3A73B7D4CE591F05B9012A24B32",
						"inventoryId": "bd99ea700090428eada9929c30ad1643",
						"inventoryName": "狮子头+炒儿菜+米饭[0318AM]",
						"photo": "bc9517845f494d61a78247c5c6b9cd97",
						"saleNum": 1,
						"deliverGoodNum": 0,
						"unitPrice": 13,
						"status": 0,
						"statusName": "未退货",
						"saleAmount": 13,
						"saleOrderDetailId": "346109EB104E44459DD9C1BC4E2D1CF8",
						"returnGoodsNum": 0,
						"dreturnGoodsNum": 0,
						"detailDiscount": 100,
						"star": 0,
						"voteContent": 0,
						"salePrice": 13.0,
						"discountMoney": 0.0,
						"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
						"pointName": "网上订餐销售点",
						"tccode": "【1号套餐】",
					}
				],
				"returnGoodsFlag": 0,
				"orderDiscount": 0,
				"nodeList": [
					{"orderStatus": -1, "statusFlag": 0},
					{"orderStatus": 6, "statusFlag": 0},
					{"orderStatus": 20, "statusFlag": 0},
				],
				"goodsCode": 0,
				"refundName": 0,
				"refundStatus": 0,
				"refundStatusName": 0,
				"refundMoney": 0,
				"refundRateType": 0,
				"refundRate": 0,
				"refundtime": 0,
				"terminalType": 1,
				"refundSettingTime": 0,
				"tableNumber": 0,
				"payAsnState": 0,
				"qrContent": 0,
				"payGroupType": 0,
				"pointInfoList": [
					{
						"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
						"pointName": "网上订餐销售点",
						"details": [
							{
								"saleOrderId": "6AA0C3A73B7D4CE591F05B9012A24B32",
								"inventoryId": "bd99ea700090428eada9929c30ad1643",
								"inventoryName": "狮子头+炒儿菜+米饭[0318AM]",
								"photo": "bc9517845f494d61a78247c5c6b9cd97",
								"saleNum": 1,
								"deliverGoodNum": 0,
								"unitPrice": 13,
								"status": 0,
								"statusName": "未退货",
								"saleAmount": 13,
								"saleOrderDetailId": "346109EB104E44459DD9C1BC4E2D1CF8",
								"returnGoodsNum": 0,
								"dreturnGoodsNum": 0,
								"detailDiscount": 100,
								"star": 0,
								"voteContent": 0,
								"salePrice": 13.0,
								"discountMoney": 0.0,
								"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
								"pointName": "网上订餐销售点",
								"tccode": "【1号套餐】",
							}
						],
					}
				],
				"startTime": "09:31",
				"endTime": "13:30",
				"subDate": 1709860674000,
				"tenantId": 0,
				"canceler": 0,
				"manageFee": 0.0,
				"supplementName": 0,
				"supplementStatus": 0,
				"supplementSettingTime": 0,
				"supplementMoney": 0,
				"supplementRateType": 0,
				"supplementRate": 0,
				"supplementtime": 0,
			},
		],
		"code": "11700000",
		"allNumber": 0,
	}"""


def query_sale():
	url3 = url + "/117/onlineProduct/l.do?t=0.56261379244008"
	param = {
		"orgId": "6cdda12c2bb0410e98a23b991febe17c",
		"saleType": "10",
		"saleDate": "2024-03-18",
		"pageNow": 1,
		"pageSize": 28,
		"codeList": ["Default_Code"],
	}
	response = requests.post(url3, params=param, headers=header)
	content = json.loads(response.text)
	meals = list()
	for i in content["result"]:
		temp = meal()
		temp.number = i["tccode"]
		temp.content = i["inventoryName"]
		temp.status = i["saleTypeName"]
		meals.append(temp)
	return meals
	example = """{
	"pageNow": 1,
	"pageSize": 12,
	"total": 28,
	"result": [
		{
			"saleMode": 0,
			"saleDate": 1710691200000,
			"saleType": "10",
			"saleTypeName": "中餐",
			"bigCategory": "3EF7D6B55EFD499AB8025E239F06A169",
			"smallCategory": "812086E8B42A412C9DE70F927072863D",
			"salePrice": 13.0,
			"inventoryId": "bd99ea700090428eada9929c30ad1643",
			"inventoryName": "狮子头+炒儿菜+米饭[0318AM]",
			"inventoryType": 2,
			"inventoryTypeName": "套餐",
			"photo": "bc9517845f494d61a78247c5c6b9cd97",
			"historyTotalCount": 0,
			"lockCount": 0,
			"saleCount": 140,
			"residueCount": 0,
			"shoppingCartCount": 0,
			"limitCount": 1,
			"characterList": 0,
			"planDetailId": "36d9c9c022ca4b86959bcbaa9483a04a",
			"shelf": -1,
			"upSource": 0,
			"memoryCode": "sztcecmf0318AM",
			"discountPrice": 13,
			"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
			"pointName": "网上订餐销售点",
			"startTime": "09:31",
			"endTime": "13:30",
			"tccode": "【1号套餐】"
		},
		{
			"saleMode": 0,
			"saleDate": 1710691200000,
			"saleType": "10",
			"saleTypeName": "中餐",
			"bigCategory": "3EF7D6B55EFD499AB8025E239F06A169",
			"smallCategory": "4384A4EF1BE543459421E0E46E2485D5",
			"salePrice": 16.0,
			"inventoryId": "a9353f32ff5c4ab9980c700fcfd64cbd",
			"inventoryName": "红烧仔排+卤豆腐干+炒盘菜头+米饭[0318AM]",
			"inventoryType": 2,
			"inventoryTypeName": "套餐",
			"photo": "4cbf8e2dcc74418b8fb65d9c813516e4",
			"historyTotalCount": 0,
			"lockCount": 0,
			"saleCount": 0,
			"residueCount": 0,
			"shoppingCartCount": 0,
			"limitCount": 1,
			"characterList": 0,
			"planDetailId": "1e521976d3b24a3484f76c1d85ab7191",
			"shelf": 1,
			"upSource": 0,
			"memoryCode": "hszpldfgcpctmf0318AM",
			"discountPrice": 16,
			"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
			"pointName": "网上订餐销售点",
			"startTime": "09:31",
			"endTime": "13:30",
			"tccode": "【2号套餐】"
		},
		{
			"saleMode": 0,
			"saleDate": 1710691200000,
			"saleType": "10",
			"saleTypeName": "中餐",
			"bigCategory": "3EF7D6B55EFD499AB8025E239F06A169",
			"smallCategory": "812086E8B42A412C9DE70F927072863D",
			"salePrice": 13.0,
			"inventoryId": "9e704acc6dc142218c4503ab102e9441",
			"inventoryName": "香辣肥肠+黄瓜炒蛋+米饭[0318AM]",
			"inventoryType": 2,
			"inventoryTypeName": "套餐",
			"photo": "b171d5fa2c23487f9b3db249d8a4c56b",
			"historyTotalCount": 0,
			"lockCount": 0,
			"saleCount": 140,
			"residueCount": 75,
			"shoppingCartCount": 0,
			"limitCount": 1,
			"characterList": 0,
			"planDetailId": "eebd57d3e5f94cf9b618c556b81d6d69",
			"shelf": 1,
			"upSource": 0,
			"memoryCode": "xlfchgcdmf0318AM",
			"discountPrice": 13,
			"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
			"pointName": "网上订餐销售点",
			"startTime": "09:31",
			"endTime": "13:30",
			"tccode": "【3号套餐】"
		},
		{
			"saleMode": 0,
			"saleDate": 1710691200000,
			"saleType": "10",
			"saleTypeName": "中餐",
			"bigCategory": "3EF7D6B55EFD499AB8025E239F06A169",
			"smallCategory": "4384A4EF1BE543459421E0E46E2485D5",
			"salePrice": 15.0,
			"inventoryId": "1b536f6588d94a00a5ec645e4a0a8504",
			"inventoryName": "红烧鸡翅根+葱油金针菇+清炒丝瓜+米饭[0318AM]",
			"inventoryType": 2,
			"inventoryTypeName": "套餐",
			"photo": "04dd35764bc94a179f970d191dace66e",
			"historyTotalCount": 0,
			"lockCount": 0,
			"saleCount": 0,
			"residueCount": 0,
			"shoppingCartCount": 0,
			"limitCount": 1,
			"characterList": 0,
			"planDetailId": "d9544481edd240dd8f73984d4d0d8a1c",
			"shelf": 1,
			"upSource": 0,
			"memoryCode": "hsjcgcyjzgqcsgmf0318AM",
			"discountPrice": 15,
			"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
			"pointName": "网上订餐销售点",
			"startTime": "09:31",
			"endTime": "13:30",
			"tccode": "【4号套餐】"
		},
		{
			"saleMode": 0,
			"saleDate": 1710691200000,
			"saleType": "10",
			"saleTypeName": "中餐",
			"bigCategory": "3EF7D6B55EFD499AB8025E239F06A169",
			"smallCategory": "812086E8B42A412C9DE70F927072863D",
			"salePrice": 12.0,
			"inventoryId": "62b0a53952e94a6694e5281a247859f0",
			"inventoryName": "京酱肉丝+炒盘菜头+米饭[0318AM]",
			"inventoryType": 2,
			"inventoryTypeName": "套餐",
			"photo": "7fe66451c2f842e2a28db5f2338f4212",
			"historyTotalCount": 0,
			"lockCount": 0,
			"saleCount": 0,
			"residueCount": 0,
			"shoppingCartCount": 0,
			"limitCount": 1,
			"characterList": 0,
			"planDetailId": "726f9d6f18264e639f7be80487f68417",
			"shelf": 1,
			"upSource": 0,
			"memoryCode": "jjrscpctmf0318AM",
			"discountPrice": 12,
			"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
			"pointName": "网上订餐销售点",
			"startTime": "09:31",
			"endTime": "13:30",
			"tccode": "【5号套餐】"
		},
		{
			"saleMode": 0,
			"saleDate": 1710691200000,
			"saleType": "10",
			"saleTypeName": "中餐",
			"bigCategory": "3EF7D6B55EFD499AB8025E239F06A169",
			"smallCategory": "ED5092065B654FA38DBEC01F557E228F",
			"salePrice": 9.0,
			"inventoryId": "b0f4affe2e52493aa276df6e8d18b7e6",
			"inventoryName": "鸡腿菇肉丝+清炒丝瓜+米饭[0318AM]",
			"inventoryType": 2,
			"inventoryTypeName": "套餐",
			"photo": "60fedf89ba264185825281888c1bd60e",
			"historyTotalCount": 0,
			"lockCount": 0,
			"saleCount": 0,
			"residueCount": 0,
			"shoppingCartCount": 0,
			"limitCount": 1,
			"characterList": 0,
			"planDetailId": "817a7b8a1c8649ffa02ba6ccd1013132",
			"shelf": 1,
			"upSource": 0,
			"memoryCode": "jtgrsqcsgmf0318AM",
			"discountPrice": 9,
			"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
			"pointName": "网上订餐销售点",
			"startTime": "09:31",
			"endTime": "13:30",
			"tccode": "【6号套餐】"
		},
		{
			"saleMode": 0,
			"saleDate": 1710691200000,
			"saleType": "10",
			"saleTypeName": "中餐",
			"bigCategory": "3EF7D6B55EFD499AB8025E239F06A169",
			"smallCategory": "19027B09C9C94360A8643B583250F2E3",
			"salePrice": 8.0,
			"inventoryId": "47268bb41c1d4da89b72a12efbcb30e8",
			"inventoryName": "炒儿菜+卤豆腐干+米饭[0318AM]",
			"inventoryType": 2,
			"inventoryTypeName": "套餐",
			"photo": "694afe5277954bf5be3063772f4a8c62",
			"historyTotalCount": 0,
			"lockCount": 0,
			"saleCount": 0,
			"residueCount": 0,
			"shoppingCartCount": 0,
			"limitCount": 1,
			"characterList": 0,
			"planDetailId": "11351e3fc80b4de688f60117ab543674",
			"shelf": 1,
			"upSource": 0,
			"memoryCode": "cecldfgmf0318AM",
			"discountPrice": 8,
			"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
			"pointName": "网上订餐销售点",
			"startTime": "09:31",
			"endTime": "13:30",
			"tccode": "【7号套餐】"
		},
		{
			"saleMode": 0,
			"saleDate": 1710691200000,
			"saleType": "10",
			"saleTypeName": "中餐",
			"bigCategory": "3EF7D6B55EFD499AB8025E239F06A169",
			"smallCategory": "4384A4EF1BE543459421E0E46E2485D5",
			"salePrice": 16.0,
			"inventoryId": "4f43891db038446280631b80ff5fc526",
			"inventoryName": "狮子头+葱油金针菇+炒盘菜头+米饭[0318AM]",
			"inventoryType": 2,
			"inventoryTypeName": "套餐",
			"photo": "bc9517845f494d61a78247c5c6b9cd97",
			"historyTotalCount": 0,
			"lockCount": 0,
			"saleCount": 140,
			"residueCount": 0,
			"shoppingCartCount": 0,
			"limitCount": 1,
			"characterList": 0,
			"planDetailId": "484fcf5beb074f7c91812b75ba383eff",
			"shelf": -1,
			"upSource": 0,
			"memoryCode": "sztcyjzgcpctmf0318AM",
			"discountPrice": 16,
			"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
			"pointName": "网上订餐销售点",
			"startTime": "09:31",
			"endTime": "13:30",
			"tccode": "【8号套餐】"
		},
		{
			"saleMode": 0,
			"saleDate": 1710691200000,
			"saleType": "10",
			"saleTypeName": "中餐",
			"bigCategory": "3EF7D6B55EFD499AB8025E239F06A169",
			"smallCategory": "812086E8B42A412C9DE70F927072863D",
			"salePrice": 13.0,
			"inventoryId": "1583a778355b4280b6d89b50f801d0cd",
			"inventoryName": "红烧仔排+黄瓜炒蛋+米饭[0318AM]",
			"inventoryType": 2,
			"inventoryTypeName": "套餐",
			"photo": "4cbf8e2dcc74418b8fb65d9c813516e4",
			"historyTotalCount": 0,
			"lockCount": 0,
			"saleCount": 0,
			"residueCount": 0,
			"shoppingCartCount": 0,
			"limitCount": 1,
			"characterList": 0,
			"planDetailId": "2c5fa2bb326e4674a3aab2b3fca8e279",
			"shelf": 1,
			"upSource": 0,
			"memoryCode": "hszphgcdmf0318AM",
			"discountPrice": 13,
			"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
			"pointName": "网上订餐销售点",
			"startTime": "09:31",
			"endTime": "13:30",
			"tccode": "【9号套餐】"
		},
		{
			"saleMode": 0,
			"saleDate": 1710691200000,
			"saleType": "10",
			"saleTypeName": "中餐",
			"bigCategory": "3EF7D6B55EFD499AB8025E239F06A169",
			"smallCategory": "4384A4EF1BE543459421E0E46E2485D5",
			"salePrice": 16.0,
			"inventoryId": "4c585976b18a4dc3bc2c8d0faff6f2df",
			"inventoryName": "香辣肥肠+卤豆腐干+清炒丝瓜+米饭[0318AM]",
			"inventoryType": 2,
			"inventoryTypeName": "套餐",
			"photo": "b171d5fa2c23487f9b3db249d8a4c56b",
			"historyTotalCount": 0,
			"lockCount": 0,
			"saleCount": 140,
			"residueCount": 75,
			"shoppingCartCount": 0,
			"limitCount": 1,
			"characterList": 0,
			"planDetailId": "57ac9e4873874075916ede112661a9d9",
			"shelf": 1,
			"upSource": 0,
			"memoryCode": "xlfcldfgqcsgmf0318AM",
			"discountPrice": 16,
			"pointId": "2fb1b9030f6d4237a0a3e04f0a0c9478",
			"pointName": "网上订餐销售点",
			"startTime": "09:31",
			"endTime": "13:30",
			"tccode": "【10号套餐】"
		},
		{
			"saleMode": 0,
			"saleDate": 1710691200000,
			"saleType": "10",
			"saleTypeName": "中餐",
			"bigCategory": "3EF7D6B55EFD499AB8025E239F06A169",
			"smallCategory": "812086E8B42A412C9DE70F927072863D",
			"salePrice": 12.0,
			"inventoryId"