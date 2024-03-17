/*
  LongStringVietnamese: print a long Vietnamese text to
  a popular LCD1602A (Japanese ROM) using I2C (PCF8574)
  Author: Le Phuoc Loc <phuocloc@gmail.com>

  Circuit:
  - LOLIN D1 Mini:          5 (SCL),    4 (SDA)
  - ESP8266:                D1 (SCL),   D2 (SDA)
  - LOLIN D32:              22 (SCL),   21 (SDA)
  - ESP32:                  D22 (SCL),  D21 (SDA)
  Not applicable for Arduino series due to memory limit

  Coding: steps to follow
  - Include LCDI2C_Viet.h for the main class and customized characters for Vietnamese
    => All Vietnamese letters and degree (°) symbol can be printed.
  - Include ROM_Standard_JP.h for Greek symbol mappings on LCD2004A Japanese ROM
    => All English letters, sign(÷√∞→←), Greek(ΣΩαβδεθμπρ), currency(¥) symbols can be printed.
  - Create LiquidCrystal_I2C_UTF8 object with I2C address=0x27, LCD size: 16 columns, 2 rows
  - ::init(): Initialize the LCD
  - ::backlight(): Turn on the LCD backlight
  - ::print(text): print text (String or char[]) to LCD
    If no longer room to print the next word in current line, it'll be printed in next line.
    ::print(text, nsec): print long text with pause 'nsec' seconds
    If the screen is full, wait 'nsec' seconds for audience to read before printing the next part on next screen.
	Note: max 8 Vietnamese letters with diacritics printed on a screen, otherwise diacritics removed.

  https://github.com/locple/LiquidCrystal_I2C_UTF8
*/

#include <LCDI2C_Viet.h>
#include <ROM_Standard_JP.h>

LiquidCrystal_I2C_Viet lcd(0x27, 16, 2);  // I2C address: 0x27; Display size: 16x2

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.println("TIẾNG VIỆT TA... HAY THẬT....!");
  delay(5000); lcd.clear();

  String poem = "MŨM MĨM béo, MỦM MỈM cười. CỦ quả dành để biếu người CŨ xưa. KIỄNG chân, chậu KIỂNG đu đưa. \
KẺO hết, KẼO kẹt đêm mưa võng buồn. HỔ thẹn chưa HỖ trợ lương. GÃ kia GẢ bán người thương vì tiền. \
HẢO tâm lo chuyện HÃO huyền. Đi buôn LỖ vốn, nước màu LỔ LOANG. PHỦ phê chừ mới PHŨ phàng. \
Nửa đường GÃY gánh, GẢY đàn tìm vui. GÃI đầu tính ngược, tính xuôi. Còn lưng NỬA vốn NỮA thời tính sao. \
GIÃI bày GIẢI nghĩa dễ đâu. Chưa kịp ẩu ĐẢ qua cầu ĐÃ xong. Run RẨY phát RẪY dọn nương. \
GỠ rối điềm GỞ rộng đường nhân sinh. Chú RỂ bứt RỄ cây quỳnh. Ra sức BỬA củi cho mình BỮA ăn. \
BẨM thưa, bụ BẪM con người. Nói năng tao NHÃ, chim kia NHẢ mồi. MÃ ngoài mồ MẢ xinh tươi. \
Nhường cơm SẺ áo cho người SẼ vui. Linh CỮU vĩnh CỬU ai ơi. CỮ kiêng CỬ động bệnh thời sẽ qua. \
TẺ nhạt, gạo TẺ của ta. Gần mà giữ KẼ thà ra KẺ thù. KHẺ mỏ, nói KHẼ như ru. CỖ bàn, CỔ kính công phu phụng thờ. \
BỖNG dưng trầm BỔNG bất ngờ. BĨU môi dè BỈU ai chờ đợi ai. Bắt BẺ, BẼ mặt tía tai. LẺ loi lý LẼ gạt ngoài chẳng nghe. \
Ngoài vườn CHỎNG gọng CHÕNG tre. CẢI thiện, CÃI lại khó mà hoà nhau. CHĨNH (hũ) tương nghiêng, CHỈNH sửa mau. \
CỦNG cố lời nói cho nhau CŨNG đành. CỞI trói CỠI (cưỡi) ngựa phi nhanh. Xem ai cứng CỎI được dành CÕI tiên. \
BẢO ban, BÃO tố khắp miền. HẢNH nắng, HÃNH diện tuỳ duyên tuỳ thời. Hồ đầy XẢ nước cho vơi. \
Giữ gìn XÃ tắc kẻo thời suy vong. Chèo BẺO, bạc BẼO dài dòng. Quê hương rất ĐỖI ĐỔI thay phố phường. \
NGHĨ mình ngơi NGHỈ dưỡng thương. TĨNH tâm TỈNH ngộ tìm đường ẩn cư. TIỂU đội còn bận TIỄU trừ. \
Ngỡ rằng bảnh TẺN thành dư TẼN tò. SẢI tay chú SÃI thập thò. Nhân sự thừa THÃI bị toà THẢI ra. \
Đứng SỮNG, SỬNG sốt sợ ma. Trẻ thơ nói SÕI nhặt SỎI đá trôi. TRẢ nợ bằng một TRÃ xôi. NÃY giờ còn đợi hạt thôi NẢY mầm. \
Ẩn SĨ, SỈ nhục giận căm. GIẢ dại GIÃ gạo thăng trầm cho qua. QUẪN trí nghĩ QUẨN sa đà. Chấp nhận xúi QUẨY hơn là QUẪY đuôi. \
Đâm THỦNG, THŨNG xuống thấp rồi. Đòn BẨY được dịp lên đồi BẪY chim. Đội NGŨ giấc NGỦ lim dim. \
Ân SỦNG ướt SŨNG nằm im chờ thời. TỦM tỉm, đánh TŨM không lời. VĨ cầm, VĨ tuyến... VỈ ruồi giúp ta. \
Rác RƯỞI gấp RƯỠI hôm qua. ĐẨY xe, ĐẪY giấc người ta chối từ. ĐẢNG phái, ĐÃNG trí ưu tư. DỞ hơi, DỞ thói tật hư DỠ nhà. \
LẨN quẩn, LẪN lộn tuổi già. ĐỈNH chung, ĐĨNH đạc cũng là ĐỈNH cao. ĐỂ dành, hiếu ĐỄ về sau. \
Cô bé tròn trịa thật là DỄ thương. DỎNG tai, DÕNG dạc khiêm nhường. RẢNH rỗi san lấp RÃNH mương trước nhà. \
Qua NGÕ, NGỎ lời hát ca. QUẢNG cáo - thực tế cách ba QUÃNG đường. RỦ rê quyến RŨ nhiễu nhương. \
RỔ sảo, RỖ mặt vấn vương một thời. CHỬA đẻ, CHỮA bệnh ai ơi. Trường hợp HÃN hữu xin thời bỏ qua. Phá CŨI làm CỦI bếp nhà. \
Xén bớt công QUĨ, QUỈ ma chẳng từ. Hạt DẺ, đất DẼ suy tư. Sàng SẢY ít gạo đến giờ chưa xong. RỬA nhục thối RỮA mặc lòng. \
Hen SUYỄN, suy SUYỂN đợi mong bao ngày. CƯỠNG đoạt chim CƯỞNG trong tay. Xin đừng cà RỠN... RỞN gai ốc rồi. \
SỬA chữa, SỮA mẹ em ơi. SẪM màu, SẨM tối xin mời ghé thăm. MẨU bánh dành biếu MẪU thân. Đắt RẺ, ngã RẼ bao lần em qua. \
SỖ sàng, SỔ toẹt chẳng tha. GIẢ thật, GIÃ gạo cho qua tháng ngày. Gây GỔ, cây GỖ chuyền tay. \
Cánh HẨU chầu HẪU ngồi chờ đổi ngôi. Mưa rỉ RẢ mệt RÃ người. RÃO gân cốt, RẢO bước thời đi nhanh. \
Cây SẢ, suồng SÃ là anh. TẢ thực, TÃ lót để dành trẻ con. Chàng HẢNG ai mở HÃNG buôn. KỶ luật KỸ xảo mình luôn ghi lòng. \
HỦ tục, HŨ gạo ngày đông. Hỏi NGÃ khó, chớ NGÃ lòng NGẢ nghiêng....!";
  // Print long text with pause (in seconds): if no room left on screen to print,
  // delay a given time (= 4s) before clearing screen and printing the next part.
  // Not suitable for boards with small memory capacity like Arduino series
  lcd.println(poem, 4);

  delay(5000); lcd.clear();
  lcd.print("(Đinh Trực sưu tầm)");
}

void loop() {}