/*
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */

#include "user_password_auth_init.hpp"
#include <geode/Properties.hpp>
#include <geode/ExceptionTypes.hpp>

#define SECURITY_USERNAME "security-username"
#define SECURITY_PASSWORD "security-password"

using namespace apache::geode::client;

namespace geode_user_password_auth {

extern "C" {
AuthInitialize* createGeodeUserPasswordAuth(){
  return new UserPasswordAuthInit();
}
}
std::shared_ptr<Properties> UserPasswordAuthInit::getCredentials(
    const std::shared_ptr<Properties>& securityprops,
    const std::string& /*server*/) {
  
  std::shared_ptr<Cacheable> userName;
  if (securityprops == nullptr || (userName = securityprops->find(SECURITY_USERNAME)) == nullptr) {
    throw AuthenticationFailedException("UserPasswordAuthInit: user name " "property [" SECURITY_USERNAME "] not set.");
  }
  std::shared_ptr<Properties> credentials = Properties::create();
  credentials->insert(SECURITY_USERNAME, userName->toString());
  std::shared_ptr<Cacheable> passwd = securityprops->find(SECURITY_PASSWORD);
  if (passwd == nullptr) {
    passwd = CacheableString::create("");
  }
  credentials->insert(SECURITY_PASSWORD, passwd->toString());
  return credentials;
}
void UserPasswordAuthInit::close() {
}
}  // namespace geode_user_password_auth
