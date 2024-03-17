// This code is not for Arduino Uno due to memory sortage for the long string here

#include <LCDI2C_Viet.h>
#include <ROM_Standard_JP.h>

LiquidCrystal_I2C_Viet lcd(0x27, 16, 2);   // LCD1602A

void setup() {
  lcd.init();
	lcd.backlight();

  // Print long string, not suitable for boards with small memory capacity like Arduino Uno
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
  lcd.println(poem, 4);
  delay(5000); lcd.clear();

  lcd.print("(Đinh Trực sưu tầm)");
}

void loop() {}