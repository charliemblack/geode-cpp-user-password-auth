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
LIBEXP AuthInitialize* createGeodeUserPasswordAuth() {
  return new UserPasswordAuthInit();
}
}

PropertiesPtr UserPasswordAuthInit::getCredentials(PropertiesPtr& securityprops, const char* server) {
  CacheablePtr userName;
  if (securityprops == NULLPTR || (userName = securityprops->find(SECURITY_USERNAME)) == NULLPTR) {
    throw AuthenticationFailedException("UserPasswordAuthInit: user name " "property [" SECURITY_USERNAME "] not set.");
  }
  PropertiesPtr credentials = Properties::create();
  credentials->insert(SECURITY_USERNAME, userName->toString()->asChar());
  CacheablePtr passwd = securityprops->find(SECURITY_PASSWORD);
  if (passwd == NULLPTR) {
    passwd = CacheableString::create("");
  }
  credentials->insert(SECURITY_PASSWORD, passwd->toString()->asChar());
  return credentials;
}
}  // namespace geode_user_password_auth
